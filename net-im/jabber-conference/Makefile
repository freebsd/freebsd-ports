# New ports collection makefile for:	jabber-conference
# Date created:			15 Apr 2002
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	conference
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	jabber-
DIST_SUBDIR=	jabber

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Jabber Conferencing module

LIB_DEPENDS=	jabberd.1:${PORTSDIR}/net-im/jabber

USE_GMAKE=	yes

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/jabber \
		-I${LOCALBASE}/include/pth

MAKE_ARGS+=	MCFLAGS="-shared" \
		LDFLAGS="-L${LOCALBASE}/lib/pth -L${LOCALBASE}/lib/jabber"

SUB_FILES+=	pkg-message README.jabberd14
DOCSDIR=	${TARGETDIR}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(NOPORTDOCS)
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/conference.so ${TARGETDIR}/lib/jabber/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/README.jabberd14 ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
