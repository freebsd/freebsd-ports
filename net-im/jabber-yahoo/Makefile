# New ports collection makefile for:	jabber-yahoo
# Date created:			12 Oct 2002
# Whom:				Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	yahoo
PORTVERSION=	2.3.2
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://files.jabberstudio.org/yahoo-transport-2/
PKGNAMEPREFIX=	jabber-
DISTNAME=	yahoo-transport-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Jabber Yahoo Transport module

LIB_DEPENDS=	jabberd.1:${PORTSDIR}/net-im/jabber

USE_GNOME=	glib12
USE_GMAKE=	yes
USE_ICONV=	yes

WRKSRC=		${WRKDIR}/yahoo-transport-${PORTVERSION}

DOCSDIR=	${TARGETDIR}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

SUB_FILES+=	README.jabberd14 pkg-message

DOCS=		CHANGES INSTALL LICENSE README jabber.xml yahoo-jabber.xml yahoo-jcr.xml

.if !defined(NOPORTDOCS)
PKG_MESSAGE=	${WRKDIR}/pkg-message
.endif

.include <bsd.port.pre.mk>

.if exists(${GLIB_CONFIG})
GLIB_CFLAGS!=	${GLIB_CONFIG} --cflags
GLIB_LIBS!=	${GLIB_CONFIG} --libs
.endif

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/jabber \
		-I${LOCALBASE}/include/pth ${GLIB_CFLAGS}

MAKE_ARGS+=	MCFLAGS="-shared" \
		LDFLAGS="-L${LOCALBASE}/lib/pth -L${LOCALBASE}/lib/jabber" \
		LIBS="${GLIB_LIBS}"

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yahoo-transport.so ${PREFIX}/lib/jabber/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
	@${INSTALL_DATA} ${WRKDIR}/README.jabberd14 ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
