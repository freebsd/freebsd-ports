# New ports collection makefile for:	lmtp2nntp
# Date created:				12 November 2001
# Whom:	      				Thomas Lotterer <thomas.lotterer@cw.com>
#
# $FreeBSD$
#

PORTNAME=	lmtp2nntp
PORTVERSION=	1.4.1
CATEGORIES=	mail news
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	tool/${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	OSSP mail to news gateway

LIB_DEPENDS=	str.9:${PORTSDIR}/devel/str \
		ex.10:${PORTSDIR}/devel/ossp-ex \
		sa.12:${PORTSDIR}/net/ossp-sa \
		var.11:${PORTSDIR}/devel/ossp-var

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ex=${LOCALBASE} --with-str=${LOCALBASE} \
		--with-sa=${LOCALBASE} --with-var=${LOCALBASE}

MAN8=		lmtp2nntp.8
PLIST_FILES=	sbin/lmtp2nntp

.if !defined(NOPORTDOCS)
PORTDOCS=	INSTALL README
.endif

check: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

.include <bsd.port.post.mk>
