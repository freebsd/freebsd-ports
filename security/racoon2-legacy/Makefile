# Created by: sumikawa
# $FreeBSD$

PORTNAME=	racoon2
PORTVERSION=	20100526a
PORTREVISION=	13
CATEGORIES=	security net ipv6
MASTER_SITES=	ftp://ftp.racoon2.wide.ad.jp/pub/racoon2/
PKGNAMESUFFIX=	legacy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Racoon2 IPsec daemon

CONFLICTS=	racoon2-[0-9]*

USES=		perl5 tar:tgz ssl
CONFIGURE_ARGS+=	--disable-kinkd
PLIST_SUB+=	KINK="@comment "

DEPRECATED=	To retire when FreeBSD 11 is EOL
EXPIRATION_DATE=	2021-09-30

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=/usr/bin/yacc perl_bindir=${LOCALBASE}/bin/perl5

OPTIONS_DEFINE=	DOCS
OPTIONS_RADIO=	KERBEROS
OPTIONS_RADIO_KERBEROS=	KRB5 \
		HEIMDAL_PORTS HEIMDAL_BASE
KRB5_DESC=	Build with Kerberos (security/krb5)
HEIM_AL_PORTS_DESC=	Build with Heimdal in ports (security/heimdal)
HEIMDAL_BASE_DESC=	Build with Heimdal in base

KRB5_USES=		gssapi:mit
KRB5_CONFIGURE_ON=	--enable-kinkd
KRB5_MAKE_ENV=	WITH_KINK=yes
KRB5_PLIST_SUB=		KINK=""
KRB5_LIB_DEPENDS=	libkrb5support.so:security/krb5
KRB5_RUN_DEPENDS=	kinit:security/krb5
KRB5_VARS=		KINK=yes

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS+=	INSTALL USAGE config-usage.ja.txt config-usage.txt
PORTDOCS+=	iked-memo.ja.txt libracoon.ja.txt specification.ja.txt
PORTDOCS+=	spmif.txt style.txt system-message.ja.txt
.if defined(KINK)
PORTDOCS+=	kinkd-data-struct.obj kinkd-impl.ja.txt
PORTDOCS+=	kinkd-install.ja.txt kinkd-state-txn.obj
.endif
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD} \
		-e '/INSTALL/s|\$$([a-z0-9]*dir)|$$(DESTDIR)&|' \
		-e '/INSTALL/s|\$$(prefix)|$$(DESTDIR)&|' {} +
	@${REINPLACE_CMD} 's|/var/run/racoon2|$$(DESTDIR)&|' \
		${WRKSRC}/samples/Makefile.in

post-patch-DOCS-on:
.for FILE in ${PORTDOCS}
	@${REINPLACE_CMD} -e 's|/usr/local/racoon2|${PREFIX}|' ${WRKSRC}/doc/${FILE}
.endfor

post-install:
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

.include <bsd.port.mk>
