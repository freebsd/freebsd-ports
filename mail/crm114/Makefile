# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	crm114
PORTVERSION=	20100106
PORTREVISION=	4
# WARNING change versionname in CRM114RELEASENAME too.
# portlint didn't like this variable at this place.
# So I have to put it down in this file.
CATEGORIES=	mail
MASTER_SITES=	http://crm114.sourceforge.net/tarballs/
# Oliver Eikemeier recommended the following construction
# to avoid the reduncany of the CRM114RELEASENAME and .src and
# .css extention.
DISTNAME=	${PORTNAME}-${PORTVERSION}-${CRM114RELEASENAME}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Markov based SpamFilter

LICENSE=	GPLv2

LIB_DEPENDS=	libtre.so:textproc/libtre

CRM114RELEASENAME=BlameMichelson

USE_CSTD=gnu89

OPTIONS_DEFINE=	NORMALIZEMIME DOCS EXAMPLES
NORMALIZEMIME_DESC=	Normalize MIME encoding

MAKE_ARGS=	CC="${CC}" prefix="${STAGEDIR}${PREFIX}" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--as-needed

CFLAGS+=	-DVERSION='\"${PORTVERSION}-${CRM114RELEASENAME}\"'
CFLAGS+=	-DNO_LOGL

INSTALL_TARGET=	install_binary_only

CRM_FILES=	mailfilter.crm mailfilter.cf mailreaver.crm mailtrainer.crm \
		maillib.crm shuffle.crm rewriteutil.crm rewrites.mfp \
		whitelist.mfp blacklist.mfp priolist.mfp priolist.mfp.example \
		blacklist.mfp.example whitelist.mfp.example crm114-mode.el \
		reto_procmailrc.recipe

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E \
	  -e 's,^((LD|C)FLAGS),#\1,;;s,^(prefix=),#\1,;;s,^(.*-install),#\1,' \
	  -e 's,crmregex_tre.c,crmregex_tre.o,' ${WRKSRC}/Makefile

# Peter Jeremy recommended the use of b64decode and md5 20040302
post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/crm \
		${STAGEDIR}${PREFIX}/bin/cssdiff \
		${STAGEDIR}${PREFIX}/bin/cssutil \
		${STAGEDIR}${PREFIX}/bin/osbf-util \
		${STAGEDIR}${PREFIX}/bin/cssmerge
	@${REINPLACE_CMD} -Ee 's|^(.*/openssl base64 -d/)|#\1|' \
		-e 's|/mewdecode/|/b64decode -pr/|' ${WRKSRC}/mailfilter.cf
	@${REINPLACE_CMD} -e 's|/md5sum/|/md5 -r/|' \
		-e 's|#!.*/usr/bin/crm.*|#!${PREFIX}/bin/crm|' \
		${WRKSRC}/mailfilter.crm ${WRKSRC}/mailtrainer.crm \
		${WRKSRC}/rewriteutil.crm \
		${WRKSRC}/mailreaver.crm ${WRKSRC}/shuffle.crm
	@for i in priolist.mfp whitelist.mfp; do \
		${CP} ${WRKSRC}/$${i}.example ${WRKSRC}/$${i}; \
	done
.if ${PORT_OPTIONS:MNORMALIZEMIME}
	@${REINPLACE_CMD} -Ee 's|^#(.*/normalizemime/)|\1|' \
	  ${WRKSRC}/mailfilter.cf
.else
	@${REINPLACE_CMD} -Ee 's|^#(.*/b64decode -pr/)|\1|' \
	  ${WRKSRC}/mailfilter.cf
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	for i in ${CRM_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${STAGEDIR}${EXAMPLESDIR}; \
	done
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@for i in ${WRKSRC}/[^G]*.txt ${WRKSRC}/README; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
