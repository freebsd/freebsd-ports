# New ports collection makefile for:   gone
# Date created:        19 April 1998
# Whom:                marcus
#
# $FreeBSD$
#

PORTNAME=	gone
PORTVERSION=	1.3.5
CATEGORIES=	misc
MASTER_SITES=	http://jaguar.ir.miami.edu/~marcus/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A terminal locking utility with many improvements over lock(1)

MAN1=		gone.1
PLIST_FILES=	bin/gone
GNU_CONFIGURE=	yes

#
# If you would like to be able to use system passwords for gone
# override this with WITH_SETUID=yes in your environment.
# Be aware that setting gone to suid MAY be a security hole.
#
.if defined(WITH_SETUID)
CONFIGURE_ENV=	with_setuid=yes
.else
CONFIGURE_ENV=	with_setuid=no
.endif

.include <bsd.port.mk>
