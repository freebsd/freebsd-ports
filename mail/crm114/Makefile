# New ports collection makefile for:	crm114
# Date created:				23 February 2004
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	crm114
PORTVERSION=	20040221
# WARNING change versionname in CRM114RELEASENAME too.
# portlint didn't like this variable at this place.
# So I have to put it down in this file.
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	crm114
# Oliver Eikemeier recommended the following construction
# to avoid the reduncany of the CRM114RELEASENAME and .src and
# .css extention.
DISTNAME=	${PORTNAME}-${PORTVERSION}-${CRM114RELEASENAME}.src
DISTFILES=	${DISTNAME}.tar.gz ${DISTNAME:R}.css.tar.gz

MAINTAINER=	Meno.Abels@Adviser.com
COMMENT=	An Markov based SpamFilter

LIB_DEPENDS=	tre.4:${PORTSDIR}/textproc/libtre

CRM114RELEASENAME=BlameYokohama

USE_GETTEXT=	yes
USE_ICONV=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}" \
		LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-L${LOCALBASE}/lib -liconv -lintl

CRM_FILES=	classifytest.crm exectest.crm inserttest_a.crm \
		inserttest_b.crm learntest.crm mailfilter.crm \
		matchtest.crm overalterisolatedtest.crm \
		windowtest.crm

post-build:
	${MKDIR} ${WRKSRC}/fbsdinstall
.for i in ${CRM_FILES}
	${SED} "1s|/usr/bin/crm|${PREFIX}/bin/crm|g" ${WRKSRC}/${i} > ${WRKSRC}/fbsdinstall/${i}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in CRM114_Mailfilter_HOWTO.txt FAQ.txt INTRO.txt QUICKREF.txt README \
	classify_details.txt COLOPHON.txt knownbugs.txt things_to_do.txt
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for i in procmailrc.recipe blacklist.mfp mailfilter.cf whitelist.mfp priolist.mfp
	${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
.for i in ${CRM_FILES}
	${INSTALL_DATA} ${WRKSRC}/fbsdinstall/${i} ${EXAMPLESDIR}
.endfor
.for i in nonspam.css spam.css
	${INSTALL_DATA} ${WRKSRC}/../${PORTNAME}-${PORTVERSION}-${CRM114RELEASENAME}.css/${i} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
