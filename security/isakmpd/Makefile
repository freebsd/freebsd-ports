# New ports collection Makefile for:	ISAKMP daemon
# Date created:				Fri May 11 18:20:02 EEST 2001
# Whom:					Martti Kuparinen <martti.kuparinen@iki.fi>
#
# $FreeBSD$
#
# NOTE: See NetBSD's /usr/pkgsrc/security/isakmpd if this package
#       should be updated!
#

PORTNAME=	isakmpd
PORTVERSION=	20020403
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_NETBSD}
MASTER_SITE_SUBDIR=	LOCAL_PORTS

MAINTAINER=	ports@FreeBSD.org

FORBIDDEN=	"unconfirmed reports of security bug--see <URL:http://www.openbsd.org/errata.html\#isakmpd> and <URL:http://www.kb.cert.org/vuls/id/287771>"

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
BROKEN=		"requires IPsec support"
.endif

USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/isakmpd
MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

MAN5=		isakmpd.conf.5 isakmpd.policy.5
MAN8=		isakmpd.8
MANCOMPRESSED=	yes

.include <bsd.port.mk>
