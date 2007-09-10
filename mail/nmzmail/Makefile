# ex:ts=8
# New ports collection Makefile for: nmzmail
# Date created:		7 January 2005
# Whom:			fernan@iib.unsam.edu.ar
#
# $FreeBSD$
#

PORTNAME=	nmzmail
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/ CENKES

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Fast mail searching for mutt

RUN_DEPENDS=	namazu:${PORTSDIR}/databases/namazu2

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

PLIST_FILES=	bin/nmzmail
PORTDOCS=	README	NEWS

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
