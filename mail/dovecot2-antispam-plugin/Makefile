# Created by: Denis Shaposhnikov <dsh@bamus.cz>
# $FreeBSD$

PORTNAME=	dovecot2-antispam-plugin
PORTVERSION=	20101222
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	http://www.bamus.cz/distfiles/
DISTFILES=	dovecot-antispam-plugin-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dovecot 2.x plugin for spam systems training

BUILD_DEPENDS=	dovecot>=2.0.7:${PORTSDIR}/mail/dovecot2 \
		gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	dovecot>=2.0.7:${PORTSDIR}/mail/dovecot2

CONFLICTS=	dovecot-antispam-1.*
WRKSRC=		${WRKDIR}/dovecot-antispam-plugin-43880985e3dd

USE_AUTOTOOLS=	aclocal autoheader autoconf
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/dovecot

ACLOCAL_ARGS=	-I m4

MAN7=		dovecot-antispam.7

PLIST_FILES=	lib/dovecot/lib90_antispam_plugin.so
PLIST_DIRSTRY=	lib/dovecot

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
