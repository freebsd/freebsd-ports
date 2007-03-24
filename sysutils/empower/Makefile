# New ports collection makefile for:	empower
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	empower
PORTVERSION=	20070223
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A graphical sudo tool based on the EFL

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	evas ecore edje
WANT_EFL=	yes
GNU_CONFIGURE=	yes

OPTIONS=	EWL "Build EWL backend" on \
		ETK "Build ETK backed" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_EWL) && !defined(WITH_ETK)
BROKEN=		you should select either ETK or EWL
.endif

.if !defined(WITHOUT_EWL) || ${HAVE_EFL:Mewl}
USE_EFL+=	ewl
PLIST_FILES+=	bin/empower_ewl
.endif

.if defined(WITH_ETK) || ${HAVE_EFL:Metk}
USE_EFL+=	etk
PLIST_FILES+=	bin/empower_etk
.endif

.include <bsd.port.post.mk>
