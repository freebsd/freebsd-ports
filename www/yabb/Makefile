# New ports collection makefile for:	yabb
# Date created:		20 October 2005
# Whom:			Andrew Pantyukhin <infofarmer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	yabb
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	YaBB_${PORTVERSION}

MAINTAINER=	infofarmer@gmail.com
COMMENT=	The original free open-source forum written in Perl

BROKEN=		Left over files

USE_ZIP=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
WWWDOCROOT?=	www
YABBSUBDIR?=	yabb
YABBDIR?=	${WWWDOCROOT}/${YABBSUBDIR}
PLIST_SUB=	YABBDIR=${YABBDIR}
DIR=		${PREFIX}/${YABBDIR}
WDIR=		${WRKDIR}/public_html/yabbfiles
WCGI=		${WRKDIR}/cgi-bin/yabb2

RUN_DEPENDS+=	${SITE_PERL}/CGI/Util.pm:${PORTSDIR}/www/p5-CGI.pm \
	${SITE_PERL}/mach/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
	${SITE_PERL}/mach/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
	${SITE_PERL}/Digest/HMAC_MD5.pm:${PORTSDIR}/security/p5-Digest-HMAC

SUB_FILES=	pkg-message
SUB_LIST=	DIR=${DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
ISOFILES=	Setup.pl Admin/ManageTemplates.pl Languages/English/Admin.lng \
	Languages/English/Main.lng Templates/default/AdminCentre.template

post-extract:
	@${RM} -rf ${WCGI}/Convert ${WCGI}/Modules ${WCGI}/FixFile.pl
	@${CHMOD} -R a=,u+rwX ${WCGI}/*
	@${CHMOD} a=rx ${WCGI}/AdminIndex.pl ${WCGI}/Setup.pl ${WCGI}/YaBB.pl
	@${CHMOD} -R a-w ${WCGI}/Admin ${WCGI}/Languages ${WCGI}/Sources
	@${CHMOD} -R a=rX ${WDIR}/*
	@${CHMOD} -R u+w ${WDIR}/Attachments ${WDIR}/Templates

do-patch:
	@${SED} -i.tmp -e 's/Upload:://' ${WCGI}/Sources/Subs.pl && \
	${RM} -f ${WCGI}/Sources/Subs.pl.tmp
.ifdef WITH_UTF8
.	for _I in ${ISOFILES}
	@${SED} -i.tmp -e 's/[iI][sS][oO]-8859-1/UTF-8/' ${WCGI}/${_I} && \
	${RM} -f ${WCGI}/${_I}.tmp
.	endfor
.endif

do-install:
	@${INSTALL} -d ${DIR}
	@${CP} -npR ${WCGI}/ ${DIR}/
	@${CP} -npR ${WDIR}/ ${DIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DIR}
	@${CHMOD} a=rx ${DIR}
	@${CAT} ${PKGMESSAGE}

pre-clean:
	@${CHMOD} -R =rwX ${WRKDIR}/*

# Maintainer section
#
#grep -l 8859 `find yabb -type f`

.include <bsd.port.mk>
