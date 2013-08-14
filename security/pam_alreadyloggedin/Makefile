# Created by: green@FreeBSD.org
# $FreeBSD$

PORTNAME=	pam_alreadyloggedin
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}					\
		http://green.homeunix.org/~green/
MASTER_SITE_SUBDIR=	green

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PAM module based on whether a user is already logged in

MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900007
BROKEN=		Does not build with utmpx.
.endif

MAN8=		pam_alreadyloggedin.8
PLIST_FILES=	lib/pam_alreadyloggedin.so lib/pam_alreadyloggedin.so.2

do-configure:
	${LN} -s ${FILESDIR}/Makefile.inc ${WRKDIR}/

.include <bsd.port.post.mk>
