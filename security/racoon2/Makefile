# Created by: sumikawa
# $FreeBSD$

PORTNAME=	racoon2
PORTVERSION=	20100526a
PORTREVISION=	5
CATEGORIES=	security net ipv6
MASTER_SITES=	ftp://ftp.racoon2.wide.ad.jp/pub/racoon2/

MAINTAINER= 	cy@FreeBSD.org
COMMENT=	Racoon2 IPsec daemon

USES=		perl5 tar:tgz
USE_RC_SUBR=	YES
USE_OPENSSL=	YES

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${STAGEDIR}${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/racoon2
CONFIGURE_ENV=	YACC=/usr/bin/yacc

OPTIONS_DEFINE=	KINK DOCS
KINK_DESC=	Enable KINK support

.include <bsd.port.pre.mk>

PLIST_SUB+=	PFX=${PREFIX}

pre-configure:
.if ${PORT_OPTIONS:MKINK}
.if !exists(/usr/lib/libkrb5.a)
	@${ECHO_MSG} 'Required Kerberos5 is not in this system.  Disable KINK support.'
CONFIGURE_ARGS+=	--disable-kinkd
PLIST_SUB+=	KINK="@comment "
.else
CONFIGURE_ARGS+=	--enable-kinkd
MAKE_ENV=	WITH_KINK=yes
PLIST_SUB+=	KINK=""
.endif
.else
CONFIGURE_ARGS+=	--disable-kinkd
PLIST_SUB+=	KINK="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS+=	INSTALL USAGE config-usage.ja.txt config-usage.txt
PORTDOCS+=	iked-memo.ja.txt libracoon.ja.txt specification.ja.txt
PORTDOCS+=	spmif.txt style.txt system-message.ja.txt
.if ${PORT_OPTIONS:MKINK}
PORTDOCS+=	kinkd-data-struct.obj kinkd-impl.ja.txt
PORTDOCS+=	kinkd-install.ja.txt kinkd-state-txn.obj
.endif
.endif

post-patch:
.if ${PORT_OPTIONS:MDOCS}
.for FILE in ${PORTDOCS}
	@${REINPLACE_CMD} -e 's|/usr/local/racoon2|${PREFIX}|' ${WRKSRC}/doc/${FILE}
.endfor
.endif

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e '/INSTALL/s|\$$([a-z].*dir)|${STAGEDIR}&|'
	@${REINPLACE_CMD} -e '/INSTALL/s|\$$(prefix)|${STAGEDIR}&|' ${WRKSRC}/pskgen/Makefile
	@${REINPLACE_CMD} -e '1s|/usr/bin/perl|${PERL}|' ${WRKSRC}/pskgen/pskgen
	@${REINPLACE_CMD} -e '/^prefix=/s|/usr/local|${STAGEDIR}${PREFIX}|;/\/var\/run\/racoon2/d' ${WRKSRC}/samples/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.jp ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@if [ -z `/sbin/sysctl -a | ${GREP} -q ipsec && echo ipsec` ]; then \
	    ${ECHO_MSG} "WARNING: IPsec feature is disabled on this host"; \
	    ${ECHO_MSG} "         You must build the kernel if you want to run racoon on the host"; \
	fi ;

.include <bsd.port.post.mk>
