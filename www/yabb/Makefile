# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yabb
PORTVERSION=	2.5.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/YaBB%202/${PORTVERSION}
DISTNAME=	YaBB_${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	The original free open-source forum written in Perl

LICENSE=	YABB_PUBLIC_LICENCE
LICENSE_NAME=	YABB PUBLIC LICENCE
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.yabbforum.com/licenses.php
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

RUN_DEPENDS=	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC

NO_PACKAGE=	complicated (de)installation paradigm
USES=		perl5 zip
USE_PERL5=	run
NO_BUILD=	yes
WWWDOCROOT?=	www
YABBSUBDIR?=	yabb
YABBDIR?=	${WWWDOCROOT}/${YABBSUBDIR}
PLIST_SUB=	YABBDIR=${YABBDIR}
DIR=		${PREFIX}/${YABBDIR}
WDIR=		${WRKSRC}/public_html/yabbfiles
WCGI=		${WRKSRC}/cgi-bin/yabb2
SUB_FILES=	pkg-message
SUB_LIST=	DIR=${DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
ISOFILES=	Admin/ManageTemplates.pl Admin/ModuleChecker.pl Languages/English/Admin.lng \
		Languages/English/Email.lng Languages/English/Main.lng \
		Setup.pl Sources/Palette.pl Sources/Post.pl Sources/Profile.pl \
		Templates/blue_1/AdminCentre.template Templates/default/AdminCentre.template \
		Templates/yabb21/AdminCentre.template Templates/yabb25/AdminCentre.template

NO_STAGE=	yes
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
	@${CP} -npR ${WCGI}/ ${DIR}/ || ${TRUE}
	@${CP} -npR ${WDIR}/ ${DIR}/ || ${TRUE}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DIR}
	@${CHMOD} a=rx ${DIR}
	@${CP} -fpR ${FILESDIR}/checksum.sha256 ${DIR}/
	@${CAT} ${PKGMESSAGE}

pre-clean:
	@${CHMOD} -Rf +rwX ${WRKDIR}/* 2>/dev/null || true

# Maintainer section
# The result goest to ISOFILES
#grep -l 8859 `find yabb -type f`

.include <bsd.port.post.mk>
