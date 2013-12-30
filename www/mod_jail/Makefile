# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	mod_jail
PORTVERSION=	0.5.2
CATEGORIES=	www
MASTER_SITES=	http://mod-jail.googlecode.com/files/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module to enable an easy alternative to mod_chroot

LICENSE=	APACHE20

USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${REINPLACE_CMD} -e "s|= apxs|= ${APXS}|" ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
