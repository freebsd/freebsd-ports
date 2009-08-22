# New ports collection makefile for:	proxychains
# Date created:		14 jui 2003
# Whom:			Patrick MARIE <mycroft@virgaria.org>
# $FreeBSD$

PORTNAME=	proxychains
PORTVERSION=	3.1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/version%20${PORTVERSION}

MAINTAINER=	mycroft@virgaria.org
COMMENT=	Redirect connection through proxy servers

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700017
EXTRA_PATCHES=	${PATCHDIR}/gethostbyaddr-proto-int
.endif

post-configure:
	@${ECHO_CMD} '#define PREFIX "${PREFIX}"' >> ${WRKSRC}/config.h

.include <bsd.port.post.mk>
