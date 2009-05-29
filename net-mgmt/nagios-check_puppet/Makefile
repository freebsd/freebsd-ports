# New ports collection makefile for:	nagios-check_puppet
# Date created:				Wed 27 May 2009
# Whom:					Alexey V. Degtyarev
#
# $FreeBSD$
#

PORTNAME=	check_puppet
PORTVERSION=	1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Nagios plugin for checking Puppet daemon availability

NO_BUILD=	yes

MAN1=		check_puppet.1
MANS=		${MAN1}

SUB_FILES=	pkg-message

PLIST_FILES=	bin/check_puppet

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/check_puppet ${PREFIX}/bin/check_puppet
.for man in ${MANS}
	${INSTALL_MAN} ${WRKSRC}/${man} ${MAN${man:E}PREFIX}/man/man${man:E}
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
