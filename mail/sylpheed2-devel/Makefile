# New ports collection makefile for:	sylpheed
# Date created:                 15 June 2000
# Whom:                         shigeri <shigeri@m10.alpha-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	sylpheed
PORTVERSION=	0.4.63
CATEGORIES=	mail ipv6
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/

MAINTAINER=	shigeri@m10.alpha-net.ne.jp

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-compface --disable-gdk-pixbuf --enable-ipv6

PORTDOCS=	ChangeLog ChangeLog.jp INSTALL INSTALL.jp README README.jp \
		TODO.jp

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sylpheed
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/sylpheed
.endfor
.endif

.include <bsd.port.mk>
