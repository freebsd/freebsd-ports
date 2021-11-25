# Created by: sumikawa

PORTNAME=	racoon2
PORTVERSION=	${RACOON2_COMMIT_DATE}
PORTREVISION=	1
CATEGORIES=	security net
HASH=		7ee335e
RACOON2_COMMIT_DATE=202000908

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Racoon2 IPsec daemon

CONFLICTS=	racoon2-legacy

USE_GITHUB=	yes
GH_ACCOUNT=	zoulasc
GH_TAGNAME=	${HASH}

USES=		autoreconf libtool:build perl5 tar:tgz ssl
CONFIGURE_ARGS+=	--enable-natt \
			--prefix=${STAGEDIR}/${PREFIX}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=/usr/bin/yacc perl_bindir=${LOCALBASE}/bin/perl \
		STAGEDIR=${STAGEDIR} PREFIX=${PREFIX}

MAKE_ENV=	STAGEDIR=${STAGEDIR} PREFIX=${PREFIX}

CFLAGS=		-DHAVE_CONFIG_H

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS+=	INSTALL USAGE config-usage.ja.txt config-usage.txt
PORTDOCS+=	iked-memo.ja.txt libracoon.ja.txt specification.ja.txt
PORTDOCS+=	spmif.txt style.txt system-message.ja.txt
.endif

post-patch:
	# @${REINPLACE_CMD} 's|/var/run/racoon2|$$(STAGEDIR)&|' \
		${WRKSRC}/samples/Makefile.in
	${REINPLACE_CMD} 's|$$(sysconfdir)|${STAGEDIR}/${PREFIX}/etc|' ${WRKSRC}/samples/rc.d/Makefile.am
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
