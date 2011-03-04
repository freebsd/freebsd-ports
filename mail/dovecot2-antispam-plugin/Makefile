# New ports collection makefile for:	dovecot2-antispam-plugin
# Date created:		Sat Jan 15 15:46:01 CET 2011
# Whom:			Denis Shaposhnikov <dsh@bamus.cz>
#
# $FreeBSD$
#

PORTNAME=	dovecot2-antispam-plugin
PORTVERSION=	20101222
CATEGORIES=	mail
MASTER_SITES=	http://www.bamus.cz/distfiles/
DISTFILES=	dovecot-antispam-plugin-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	dsh@bamus.cz
COMMENT=	The dovecot 2.x plugin for spam systems training.

BUILD_DEPENDS=	${RUN_DEPENDS} \
		gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	dovecot>=2.0.7:${PORTSDIR}/mail/dovecot2

CONFLICTS=	dovecot-antispam-1.*
WRKSRC=		${WRKDIR}/dovecot-antispam-plugin-43880985e3dd

USE_AUTOTOOLS=	aclocal autoheader autoconf
USE_BZIP2=	yes
USE_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/dovecot

ACLOCAL_ARGS=	-I m4

MAN7=		dovecot-antispam.7

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
