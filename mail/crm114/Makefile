# New ports collection makefile for:	crm114
# Date created:				23 February 2004
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	crm114
PORTVERSION=	20070301
# WARNING change versionname in CRM114RELEASENAME too.
# portlint didn't like this variable at this place.
# So I have to put it down in this file.
CATEGORIES=	mail
MASTER_SITES=	http://crm114.sourceforge.net/
MASTER_SITE_SUBDIR=	crm114
# Oliver Eikemeier recommended the following construction
# to avoid the reduncany of the CRM114RELEASENAME and .src and
# .css extention.
DISTNAME=	${PORTNAME}-${PORTVERSION}-${CRM114RELEASENAME}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Markov based SpamFilter

LIB_DEPENDS=	tre.6:${PORTSDIR}/textproc/libtre
# there is no other then formail on this planet
RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

CRM114RELEASENAME=BlameBaltar

USE_GETTEXT=	yes
USE_ICONV=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}" \
		LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-L${LOCALBASE}/lib -liconv -lintl

INSTALL_TARGET=	install_binary_only

CRM_FILES=	mailfilter.crm mailtrainer.crm procmailrc.recipe mailfilter.cf \
		priolist.mfp whitelist.mfp blacklist.mfp classifytest.crm \
		exectest.crm inserttest_a.crm inserttest_b.crm learntest.crm \
		matchtest.crm overalterisolatedtest.crm windowtest.crm \
		mailreaver.crm shuffle.crm maillib.crm

post-patch:
	@${REINPLACE_CMD} -Ee 's,^((LD|C)FLAGS),#\1,;;s,^(prefix=),#\1,;;s,^(.*-install),#\1,' \
		${WRKSRC}/Makefile

# Peter Jeremy recommended the use of b64decode and md5 20040302
post-install:
	@${REINPLACE_CMD} -Ee 's|^(.*/openssl base64 -d/)|#\1|' \
		-e 's|/mewdecode/|/b64decode -pr/|' ${WRKSRC}/mailfilter.cf
	@${REINPLACE_CMD} -e 's|/md5sum/|/md5 -r/|' \
		-e 's|#!.*/usr/bin/crm.*|#!${PREFIX}/bin/crm|' \
		${WRKSRC}/mailfilter.crm ${WRKSRC}/mailtrainer.crm ${WRKSRC}/mailreaver.crm
	@for i in priolist.mfp whitelist.mfp; do \
		${CP} ${WRKSRC}/$${i}.example ${WRKSRC}/$${i}; \
	done
.ifdef(WITH_NORMALIZEMIME)
	@${REINPLACE_CMD} -Ee 's|^#(.*/normalizemime/)|\1|' ${WRKSRC}/mailfilter.cf
.else
	@${REINPLACE_CMD} -Ee 's|^#(.*/b64decode -pr/)|\1|' ${WRKSRC}/mailfilter.cf
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@for i in ${CRM_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${EXAMPLESDIR}; \
	done
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${WRKSRC}/[^G]*.txt ${WRKSRC}/README; do \
		${INSTALL_DATA} $${i} ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
