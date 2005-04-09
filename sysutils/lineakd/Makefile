# New ports collection makefile for: lineakd
# Date created:				03 June 2002
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	lineakd
PORTVERSION=	0.8.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=lineak
DIST_SUBDIR=	lineak

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Lineakd is a daemon which enables special keys on internet keyboards

USE_GMAKE=	yes
USE_XLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${X11BASE}/lib ${PTHREAD_LIBS}"
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS+=--program-prefix=''

PORTDOCS=	README TODO AUTHORS

MAN1=		lineakd.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
# ANSI C++ forbids data member `macro_info' with same name as enclosing class
USE_GCC=	3.4
GNU_CONFIGURE=	yes
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ltmain.sh
.else
USE_LIBTOOL_VER=15
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||' ${WRKSRC}/lineakd/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/lineakd/Makefile.in
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lineakd.conf.example ${EXAMPLESDIR}

.include <bsd.port.post.mk>
