# New ports collection makefile for:	lbdb
# Date created:		2 February 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	lbdb
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.spinnaker.de/debian/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mwest@uct.ac.za
COMMENT=	Set of tools for use with mutt's external mail address query feature

BUILD_DEPENDS=	abook:${PORTSDIR}/mail/abook \
		gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	abook:${PORTSDIR}/mail/abook \
		gpg:${PORTSDIR}/security/gnupg

WRKSRC=		${WRKDIR}/lbdb-${PORTVERSION}
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec --enable-lbdb-dotlock
USE_GMAKE=	YES
USE_PERL5=	yes

MAN1=		nodelist2lbdb.1 lbdbq.1 lbdb-fetchaddr.1 lbdb_dotlock.1 \
		mutt_ldap_query.1

.include <bsd.port.mk>
