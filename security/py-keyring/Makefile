# New ports collection makefile for:	py-keyring
# Date created:				2 September 2009
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	keyring
PORTVERSION=	0.5
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Store and access your passwords safely

#LICENSE=	PSF

LATEST_LINK=	py-${PORTNAME}

USE_KDE4=	#
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
WANT_GNOME=	yes

OPTIONS=	GNOME_KEYRING "GNOME Keyring backend" Off \
		KDE_KWALLET "KDE KWallet backend" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME_KEYRING)
USE_GNOME+=	pygnomedesktop
.endif

.if defined(WITH_KDE_KWALLET)
USE_KDE4+=	pykde4
.endif

.include <bsd.port.post.mk>
