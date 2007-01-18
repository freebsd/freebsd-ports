# New ports collection makefile for:   jailme
# Date created:        2 January 2007
# Whom:                wmoran
#
# $FreeBSD$
#

PORTNAME=	jailme
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.collaborativefusion.com/~wmoran/code/jailme/

MAINTAINER=	wmoran@collaborativefusion.com
COMMENT=	A setuid version of jexec to allow normal users access to jails

PLIST_FILES=	sbin/jailme

USE_BZIP2=	yes

BROKEN=		Unfetchable

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
