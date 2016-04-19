# Created by: sumikawa
# $FreeBSD$

PORTNAME=	racoon2
PORTVERSION=	20100526a
PORTREVISION=	10
CATEGORIES=	security net ipv6
MASTER_SITES=	ftp://ftp.racoon2.wide.ad.jp/pub/racoon2/

MAINTAINER= 	cy@FreeBSD.org
COMMENT=	Racoon2 IPsec daemon

USES=		perl5 tar:tgz
USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--disable-kinkd
PLIST_SUB+=	KINK="@comment "

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${STAGEDIR}${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/racoon2
CONFIGURE_ENV=	YACC=/usr/bin/yacc perl_bindir=${LOCALBASE}/bin/perl5

OPTIONS_DEFINE=	DOCS
OPTIONS_RADIO=	KERBEROS
OPTIONS_RADIO_KERBEROS=	KRB5 KRB5_112 KRB5_113 KRB5_114 \
		HEIMDAL_PORTS HEIMDAL_BASE
KRB5_DESC=	Build with Kerberos (security/krb5)
KRB5_112_DESC=	Build with Kerberos (security/krb5-112)
KRB5_113_DESC=	Build with Kerberos (security/krb5-113)
KRB5_114_DESC=	Build with Kerberos (security/krb5-114)
HEIM_AL_PORTS_DESC=	Build with Heimdal in ports (security/heimdal)
HEIMDAL_BASE_DESC=	Build with Heimdal in base

KRB5_USES=		gssapi:mit
KRB5_CONFIGURE_ON=	--enable-kinkd
KRB5_MAKE_ENV=	WITH_KINK=yes
KRB5_PLIST_SUB=		KINK=""
KRB5_LIB_DEPENDS=	libkrb5support.so:${PORTSDIR}/security/krb5
KRB5_RUN_DEPENDS=	kinit:${PORTSDIR}/security/krb5
KRB5_VARS=		KINK=yes

KRB5_112_USES=		gssapi:mit
KRB5_112_CONFIGURE_ON=	--enable-kinkd
KRB5_112_MAKE_ENV=	WITH_KINK=yes
KRB5_112_PLIST_SUB=	KINK=""
KRB5_112_LIB_DEPENDS=	libkrb5support.so:${PORTSDIR}/security/krb5-112
KRB5_112_RUN_DEPENDS=	kinit:${PORTSDIR}/security/krb5-112
KRB5_112_VARS=		KINK=yes

KRB5_113_USES=		gssapi:mit
KRB5_113_CONFIGURE_ON=	--enable-kinkd
KRB5_113_MAKE_ENV=	WITH_KINK=yes
KRB5_113_PLIST_SUB=	KINK=""
KRB5_113_LIB_DEPENDS=	libkrb5support.so:${PORTSDIR}/security/krb5-113
KRB5_113_RUN_DEPENDS=	kinit:${PORTSDIR}/security/krb5-113
KRB5_113_VARS=		KINK=yes

KRB5_114_USES=		gssapi:mit
KRB5_114_CONFIGURE_ON=	--enable-kinkd
KRB5_114_MAKE_ENV=	WITH_KINK=yes
KRB5_114_PLIST_SUB=	KINK=""
KRB5_114_LIB_DEPENDS=	libkrb5support.so:${PORTSDIR}/security/krb5-114
KRB5_114_RUN_DEPENDS= 	kinit:${PORTSDIR}/security/krb5-113
KRB5_114_VARS=		KINK=yes

HEIMDAL_PORT_USES=	gssapi:heimdal
HEIMDAL_PORTS_CONFIGURE_ON=	--enable-kinkd
HEIMDAL_PORTS_MAKE_ENV=	WITH_KINK=yes
HEIMDAL_PORT_PLIST_SUB=	KINK=""
HEIMDAL_PORT_VARS=	KINK=yes

HEIMDAL_BASE_USES=	gssapi:base
HEIMDAL_BASE_CONFIGURE_ON=	--enable-kinkd
HEIMDAL_BASE_MAKE_ENV=	WITH_KINK=yes
HEIMDAL_BASE_PLIST_SUB=	KINK=""
HEIMDAL_BASE_VARS=	KINK=yes

.include <bsd.port.pre.mk>

PLIST_SUB+=	PFX=${PREFIX}

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS+=	INSTALL USAGE config-usage.ja.txt config-usage.txt
PORTDOCS+=	iked-memo.ja.txt libracoon.ja.txt specification.ja.txt
PORTDOCS+=	spmif.txt style.txt system-message.ja.txt
.if defined(KINK)
PORTDOCS+=	kinkd-data-struct.obj kinkd-impl.ja.txt
PORTDOCS+=	kinkd-install.ja.txt kinkd-state-txn.obj
.endif
.endif

post-patch-DOCS-on:
.for FILE in ${PORTDOCS}
	@${REINPLACE_CMD} -e 's|/usr/local/racoon2|${PREFIX}|' ${WRKSRC}/doc/${FILE}
.endfor

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e '/INSTALL/s|\$$([a-z].*dir)|${STAGEDIR}&|'
	@${REINPLACE_CMD} -e '/INSTALL/s|\$$(prefix)|${STAGEDIR}&|' ${WRKSRC}/pskgen/Makefile
	@${REINPLACE_CMD} -e '/^prefix=/s|/usr/local|${STAGEDIR}${PREFIX}|;/\/var\/run\/racoon2/d' ${WRKSRC}/samples/Makefile

post-install:
	${MKDIR} ${STAGEDIR}/var/run/racoon2
	@if [ -z `/sbin/sysctl -a | ${GREP} -q ipsec && echo ipsec` ]; then \
	    ${ECHO_MSG} "WARNING: IPsec feature is disabled on this host"; \
	    ${ECHO_MSG} "         You must build the kernel if you want to run racoon on the host"; \
	fi ;

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.jp ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
