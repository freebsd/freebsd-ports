# New ports collection makefile for:	namefix
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	namefix
PORTVERSION=	4.0.r11
DISTVERSION=	4.RC11
CATEGORIES=	sysutils
MASTER_SITES=	CENKES # SF
DISTNAME=	${PORTNAME}.${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Batch renamer

RUN_DEPENDS=	p5-MP3-Tag>=0:${PORTSDIR}/audio/p5-MP3-Tag \
		p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-Tk-JComboBox>=0:${PORTSDIR}/x11-toolkits/p5-Tk-JComboBox \
		p5-Tk-DynaTabFrame>=0:${PORTSDIR}/x11-toolkits/p5-Tk-DynaTabFrame

WRKSRC=		${WRKDIR}/namefix.pl
NO_BUILD=	yes
USE_BZIP2=	yes
USE_PERL5=	yes

post-extract:
	@${FIND} ${WRKSRC} -name '*~' -delete

post-patch:
	@${REINPLACE_CMD} -e\
	's|$$prog_dir/libs/|${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/|'\
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@cd ${WRKSRC}/libs/&&${COPYTREE_SHARE} . ${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/

.include <bsd.port.mk>
