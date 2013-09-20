# Created by: marcus
# $FreeBSD$

PORTNAME=	gone
PORTVERSION=	1.3.6
CATEGORIES=	misc
MASTER_SITES=	http://www.marcuscom.com/downloads/gone/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A terminal locking utility with many improvements over lock(1)

MAN1=		gone.1
PLIST_FILES=	bin/gone
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	SETUID
SETUID_DESC=	Install gone setuid root for password support

NO_STAGE=	yes
.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

#
# If you would like to be able to use system passwords for gone
# override this with WITH_SETUID=yes in your environment.
# Be aware that setting gone to suid MAY be a security hole.
#
.if ${PORT_OPTIONS:MSETUID}
CONFIGURE_ENV=	with_setuid=yes
.else
CONFIGURE_ENV=	with_setuid=no
.endif

.include <bsd.port.post.mk>
