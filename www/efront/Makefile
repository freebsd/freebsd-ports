# Created by: Wen heping <wenheping@gmail.com>

PORTNAME=	efront
DISTVERSION=	3.6.14
PORTREVISION=	1
CATEGORIES=	www education
MASTER_SITES=	SF/${PORTNAME}learning/${PORTNAME}learning/eFront%20v3.6.14/
DISTNAME=	${PORTNAME}_${PORTVERSION}_build18016_community

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Elearning and Human Capital Development platform

DEPRECATED=	Unsupported by upstream
EXPIRATION_DATE=2021-09-16

USES=		cpe shebangfix zip php
SHEBANG_FILES=	www/phplivedocx/samples/mail-merge/supported-file-formats/generate-documents.php \
		www/phplivedocx/samples/mail-merge/supported-file-formats/show-supported-file-formats.php \
		www/phplivedocx/samples/mail-merge/template-info/list-template-info.php \
		www/phplivedocx/samples/mail-merge/convert-batch/run-job.php \
		www/phplivedocx/samples/mail-merge/templates/download.php \
		www/phplivedocx/samples/mail-merge/templates/upload.php \
		www/phplivedocx/samples/mail-merge/templates/template-exists.php \
		www/phplivedocx/samples/mail-merge/templates/list.php \
		www/phplivedocx/samples/mail-merge/templates/delete-all.php \
		www/phplivedocx/samples/mail-merge/license-agreement/generate-document.php \
		www/phplivedocx/samples/mail-merge/telephone-bill/generate-document.php

CPE_VENDOR=	efrontlearning
USE_PHP=	mbstring zip iconv zlib spl ldap
EFRONT_FILES=	CHANGELOG.txt index.php INSTALL.txt \
		LICENSE.txt  README.txt
EFRONT_DIRS=	libraries PEAR \
		upload www backups

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
.for i in ${EFRONT_FILES}
	@cd ${WRKSRC} && ${CP} ${i} ${STAGEDIR}${WWWDIR}
.endfor
.for i in ${EFRONT_DIRS}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${WWWDIR}
.endfor
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
