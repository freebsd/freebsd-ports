# Created by: sumikawa
# $FreeBSD$

PORTNAME=	racoon2
PORTVERSION=	${RACOON2_COMMIT_DATE}
PORTREVISION=	1
CATEGORIES=	security net
HASH=		5c4af73
RACOON2_COMMIT_DATE=20181215

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Racoon2 IPsec daemon

BROKEN_FreeBSD_11=	Requires openssl111 to build

CONFLICTS=	racoon2-legacy-*

USE_GITHUB=     yes
GH_ACCOUNT=     zoulasc
GH_TAGNAME=     ${HASH}

USES=		autoreconf:build perl5 tar:tgz ssl
CONFIGURE_ARGS+=	--enable-natt \
			--prefix=${PREFIX}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=/usr/bin/yacc perl_bindir=${LOCALBASE}/bin/perl5

# MAKE_ENV=	DESTDIR=${DESTDIR}

CFLAGS=		-DHAVE_CONFIG_H

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	DOCS NO_KRB
OPTIONS_SINGLE=	KERBEROS
OPTIONS_SINGLE_KERBEROS=	NO_KRB KRB5 HEIMDAL_PORT HEIMDAL_BASE
NO_KRB_DESC=	No Kerberos support
KRB5_DESC=	Build with Kerberos (security/krb5)
HEIMDAL_PORT_DESC=	Build with Heimdal in ports (security/heimdal)
HEIMDAL_BASE_DESC=	Build with Heimdal in base

NO_KRB_CONFIGURE_ON=	--disable-kinkd
NO_KRB_MAKE_ENV=	WITH_KINK=no
NO_KRB_PLIST_SUB=	KINK="@comment "
NO_KRB_VARS=		KINK=no

KRB5_USES=		gssapi:mit
KRB5_CONFIGURE_ON=	--enable-kinkd
KRB5_MAKE_ENV=		WITH_KINK=yes
KRB5_PLIST_SUB=		KINK=""
KRB5_LIB_DEPENDS=	libkrb5support.so:security/krb5
KRB5_RUN_DEPENDS=	kinit:security/krb5
KRB5_VARS=		KINK=yes

HEIMDAL_PORT_USES=	gssapi:heimdal
HEIMDAL_PORT_CONFIGURE_ON=	--enable-kinkd
HEIMDAL_PORT_MAKE_ENV=	WITH_KINK=yes
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
	# @${REINPLACE_CMD} 's|/var/run/racoon2|$$(STAGEDIR)&|' \
		${WRKSRC}/samples/Makefile.in
	@${LN} -sf ${LOCALBASE}/share/automake-1.16/ylwrap ${WRKSRC}/lib

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
