# New ports collection makefile for:	yabb
# Date created:		20 October 2005
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yabb
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/YaBB%202/${PORTVERSION}
DISTNAME=	YaBB_${PORTVERSION}

MAINTAINER=	rodrigo@bebik.net
COMMENT=	The original free open-source forum written in Perl

RUN_DEPENDS=	p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC

NO_PACKAGE=	complicated (de)installation paradigm
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
SUB_FILES=	pkg-message
SUB_LIST=	DIR=${DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
ISOFILES=	Setup.pl Admin/ManageTemplates.pl Languages/English/Admin.lng \
	Languages/English/Main.lng Templates/default/AdminCentre.template

.include <bsd.port.pre.mk>

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
.for _I in ${ISOFILES}
	@${SED} -i.tmp -e 's/[iI][sS][oO]-8859-1/UTF-8/' ${WCGI}/${_I} && \
	${RM} -f ${WCGI}/${_I}.tmp
.endfor

do-install:
	@${INSTALL} -d ${DIR}
	@${CP} -npR ${WCGI}/ ${DIR}/
	@${CP} -npR ${WDIR}/ ${DIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DIR}
	@${CHMOD} a=rx ${DIR}
	@${CP} -fpR ${FILESDIR}/checksum.sha256 ${DIR}/
	@${CAT} ${PKGMESSAGE}

pre-clean:
	@${CHMOD} -Rf +rwX ${WRKDIR}/* 2>/dev/null || true

# Maintainer section
#
#grep -l 8859 `find yabb -type f`
#echo '@unexec [ k`sha256 -q %D/%%YABBDIR%%/'$i'` = k`grep '\'$i\'' %D/%%YABBDIR%%/checksum.sha256 | cut -c-64` ] && rm -f %D/%%YABBDIR%%/'$i
#echo '@unexec i='\'$i\'' ; if [ k`sha256 -q %D/%%YABBDIR%%/$i` = k`grep "$i" %D/%%YABBDIR%%/checksum.sha256 | cut -c-64` ] && rm -f %D/%%YABBDIR%%/$i'
#echo '@unexec i='\'$i\''; cd %D/%%YABBDIR%% && if [ k`sha256 -q $i` = k`grep "$i\$" checksum.sha256 | cut -c-64` ]; then rm -f $i; fi'
#@cd ${DIR} && ${SHA256} -r `${FIND} * -not -type d` > checksum.sha256

.include <bsd.port.post.mk>
