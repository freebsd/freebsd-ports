# New ports collection makefile for: lineakd
# Date created:				03 June 2002
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	lineakd
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=lineak

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Lineakd is a daemon which enables special keys on internet keyboards

USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${X11BASE}/lib ${PTHREAD_LIBS}"
USE_REINPLACE=	yes

.if defined(WITHOUT_XOSD)
CONFIGURE_ARGS+=	--with-xosd=no
.else
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
.endif

PORTDOCS=	README TODO AUTHORS

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||' ${WRKSRC}/lineakd/Makefile.in
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

.include <bsd.port.mk>
