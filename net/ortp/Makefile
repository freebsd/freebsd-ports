# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ortp
PORTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	linphone/ortp/sources

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A Real-time Transport Protocol (RTP) stack

USES=		pathfix pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
USE_LDCONFIG=	yes

pre-install:
.if defined(NOPORTDOCS)
	${RM} -rf ${WRKSRC}/docs/html
.endif

.include <bsd.port.mk>
