# New ports collection makefile for:    Citadel/UX
# Date created:         Tue Jun 12 15:42:14 EDT 2001
# Whom:                 brian@shadowcom.net
#
# $FreeBSD$
#

PORTNAME=	citadel
PORTVERSION=	5.80
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://uncensored.citadel.org/pub/citadel/ \
		ftp://ftp.tux.org/pub/net/citadel/ \
		http://www.shadowcom.net/Software/Citadel-UX/
DISTNAME=	${PORTNAME}-ux-${PORTVERSION}

MAINTAINER=	brian@shadowcom.net
COMMENT=	Citadel/UX Communications Server

LIB_DEPENDS=    gdbm:${PORTSDIR}/databases/gdbm

WRKSRC=		${WRKDIR}/citadel
GNU_CONFIGURE=  yes
USE_GMAKE=      yes
CONFIGURE_ARGS=	--with-gdbm=${LOCALBASE}
IS_INTERACTIVE=	yes

post-install:
	${STRIP} ${PREFIX}/bin/aidepost
	${STRIP} ${PREFIX}/bin/base64
	${STRIP} ${PREFIX}/bin/citadel
	${STRIP} ${PREFIX}/bin/citmail
	${STRIP} ${PREFIX}/bin/citserver
	${STRIP} ${PREFIX}/bin/mailinglist
	${STRIP} ${PREFIX}/bin/msgform
	${STRIP} ${PREFIX}/bin/netmailer
	${STRIP} ${PREFIX}/bin/netpoll
	${STRIP} ${PREFIX}/bin/netproc
	${STRIP} ${PREFIX}/bin/netsetup
	${STRIP} ${PREFIX}/bin/qpdecode
	${STRIP} ${PREFIX}/bin/rcit
	${STRIP} ${PREFIX}/bin/readlog
	${STRIP} ${PREFIX}/bin/sendcommand
	${STRIP} ${PREFIX}/bin/citsetup
	${STRIP} ${PREFIX}/bin/stats
	${STRIP} ${PREFIX}/bin/userlist
	${STRIP} ${PREFIX}/bin/whobbs
	${STRIP} ${PREFIX}/share/citadel/modules/*.so
	${PREFIX}/bin/citsetup
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
