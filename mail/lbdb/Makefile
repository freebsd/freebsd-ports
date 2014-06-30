# Created by: mwest@uct.ac.za
# $FreeBSD$

PORTNAME=	lbdb
PORTVERSION=	0.39
CATEGORIES=	mail
MASTER_SITES=	http://www.spinnaker.de/debian/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Set of tools for use with mutt's external mail address query feature

RUN_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap

OPTIONS_DEFINE=	ABOOK EVOLUTION GPG
ABOOK_DESC=	abook address book support
EVOLUTION_DESC=	Ximan Evolution support
GPG_DESC=	GNU Privacy Guard support

WRKSRC=		${WRKDIR}/lbdb-${PORTVERSION}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${STAGEDIR}${PREFIX}
CONFIGURE_ARGS=	--enable-lbdb-dotlock --libdir=${STAGEDIR}${PREFIX}/libexec
USES=		gmake perl5

.include <bsd.port.options.mk>

.if exists (/usr/bin/getent)
WITH_GETENT=	yes
.endif

.if ${PORT_OPTIONS:MGPG}
BUILD_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
PLIST_SUB+=	GPG=""
.else
PLIST_SUB+=	GPG="@comment "
.endif

.if ${PORT_OPTIONS:MABOOK}
BUILD_DEPENDS+=	abook:${PORTSDIR}/mail/abook
RUN_DEPENDS+=	abook:${PORTSDIR}/mail/abook
PLIST_SUB+=	ABOOK=""
.else
PLIST_SUB+=	ABOOK="@comment "
.endif

.if ${PORT_OPTIONS:MEVOLUTION}
BUILD_DEPENDS+=	evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS+=	evolution:${PORTSDIR}/mail/evolution
PLIST_SUB+=	EVOLUTION=""
.else
PLIST_SUB+=	EVOLUTION="@comment "
.endif

.if ${PORT_OPTIONS:MGETENT}
PLIST_SUB+=	GETENT=""
.else
PLIST_SUB+=	GETENT="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's/sed/gsed/' ${WRKSRC}/m_muttalias.sh.in

post-configure:
	${REINPLACE_CMD} -e 's%mandir=.*%mandir=${STAGEDIR}${PREFIX}/man%' ${WRKSRC}/Makefile

.include <bsd.port.mk>
