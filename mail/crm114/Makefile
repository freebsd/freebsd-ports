# New ports collection makefile for:	crm114
# Date created:				23 February 2004
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	crm114
PORTVERSION=	20050518
PORTREVISION=	0
# WARNING change versionname in CRM114RELEASENAME too.
# portlint didn't like this variable at this place.
# So I have to put it down in this file.
CATEGORIES=	mail
MASTER_SITES=	http://crm114.sourceforge.net/
MASTER_SITE_SUBDIR=	crm114
# Oliver Eikemeier recommended the following construction
# to avoid the reduncany of the CRM114RELEASENAME and .src and
# .css extention.
DISTNAME=	${PORTNAME}-${PORTVERSION}.${CRM114RELEASENAME}.src

MAINTAINER=	Meno.Abels@Adviser.com
COMMENT=	An Markov based SpamFilter

LIB_DEPENDS=	tre.6:${PORTSDIR}/textproc/libtre
# there is no other then formail on this planet
RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

CRM114RELEASENAME=BlameMercury

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes

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

post-patch:
	@${REINPLACE_CMD} -Ee 's,^((LD|C)FLAGS.*),#\1,;;s,^(prefix=.*),#\1,' \
		${WRKSRC}/Makefile

# Peter Jeremy recommended the use of b64decode and md5 20040302
post-build:
	${MKDIR} ${WRKSRC}/fbsdinstall
	${SED} 's|:mime_decoder: /mewdecode/|:mime_decoder: /b64decode -pr/|' \
		 ${WRKSRC}/mailfilter.cf > ${WRKSRC}/fbsdinstall/mailfilter.cf
.for i in ${CRM_FILES}
	${SED} "1s|/usr/bin/crm|${PREFIX}/bin/crm|g" ${WRKSRC}/${i} > ${WRKSRC}/fbsdinstall/${i}
.endfor
	${SED} 's|/md5sum/|/md5 -r/|' ${WRKSRC}/mailfilter.crm > ${WRKSRC}/fbsdinstall/mailfilter.crm.md5
	${MV} ${WRKSRC}/fbsdinstall/mailfilter.crm.md5 ${WRKSRC}/fbsdinstall/mailfilter.crm

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in CRM114_Mailfilter_HOWTO.txt FAQ.txt INTRO.txt QUICKREF.txt README \
	classify_details.txt COLOPHON.txt knownbugs.txt things_to_do.txt
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for i in procmailrc.recipe blacklist.mfp fbsdinstall/mailfilter.cf whitelist.mfp priolist.mfp
	${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
.for i in ${CRM_FILES}
	${INSTALL_DATA} ${WRKSRC}/fbsdinstall/${i} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
