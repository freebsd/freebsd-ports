# New ports collection makefile for:	lbdb
# Date created:		2 February 2000
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	lbdb
PORTVERSION=	0.35.1
CATEGORIES=	mail
MASTER_SITES=	http://www.spinnaker.de/debian/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of tools for use with mutt's external mail address query feature

RUN_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

WRKSRC=		${WRKDIR}/lbdb-${PORTVERSION}
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec --enable-lbdb-dotlock
USE_GMAKE=	YES
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if exists (${LOCALBASE}/bin/gpg)
WITH_GPG=	yes
.endif
.if exists (${LOCALBASE}/bin/abook)
WITH_ABOOK=	yes
.endif
.if exists (${LOCALBASE}/bin/evolution)
WITH_EVOLUTION=	yes
.endif
.if exists (/usr/bin/getent)
WITH_GETENT=	yes
.endif

.if defined(PACKAGE_BUILDING)
WITH_GPG=	yes
WITH_ABOOK=	yes
.endif

.if defined(WITH_GPG)
BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
PLIST_SUB+=	GPG=""
.else
PLIST_SUB+=	GPG="@comment "
.endif
.if defined(WITH_ABOOK)
BUILD_DEPENDS+=	abook:${PORTSDIR}/mail/abook
RUN_DEPENDS+=	abook:${PORTSDIR}/mail/abook
PLIST_SUB+=	ABOOK=""
.else
PLIST_SUB+=	ABOOK="@comment "
.endif
.if defined(WITH_EVOLUTION)
BUILD_DEPENDS+=	evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS+=	evolution:${PORTSDIR}/mail/evolution
PLIST_SUB+=	EVOLUTION=""
.else
PLIST_SUB+=	EVOLUTION="@comment "
.endif
.if defined(WITH_GETENT)
PLIST_SUB+=	GETENT=""
.else
PLIST_SUB+=	GETENT="@comment "
.endif

MAN1=		nodelist2lbdb.1 lbdbq.1 lbdb-fetchaddr.1 lbdb_dotlock.1 \
		mutt_ldap_query.1

post-patch:
	${REINPLACE_CMD} -e 's/sed/gsed/' ${WRKSRC}/m_muttalias.sh.in

.include <bsd.port.post.mk>
