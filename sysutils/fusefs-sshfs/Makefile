# New ports collection makefile for:	fusefs-sshfs
# Date created: 			01 October 2005
# Whom:					Anish Mistry
# $FreeBSD$
#

PORTNAME=	sshfs
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fuse
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-fuse-${PORTVERSION}

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Mount remote directories over ssh

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs \
		glib-2.0.600:${PORTSDIR}/devel/glib20
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		Depends on kernel module that requires FreeBSD 6 or later
.endif

post-install:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.post.mk>
