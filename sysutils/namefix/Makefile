# New ports collection makefile for:	namefix
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	namefix
DISTVERSION=	4.0_RC3
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}.pl_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Batch renamer

RUN_DEPENDS=	p5-MP3-Tag>=0:${PORTSDIR}/audio/p5-MP3-Tag \
		p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-Tk-JComboBox>=0:${PORTSDIR}/x11-toolkits/p5-Tk-JComboBox \
		p5-Tk-DynaTabFrame>=0:${PORTSDIR}/x11-toolkits/p5-Tk-DynaTabFrame

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's!libs/!${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/!' ${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL} -d ${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
	@${CP} -R ${WRKSRC}/libs/ ${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/

.include <bsd.port.mk>
