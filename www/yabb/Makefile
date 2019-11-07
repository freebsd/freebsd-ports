# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yabb
PORTVERSION=	2.6.11
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.yabbforum.com/downloads/release/
DISTNAME=	YaBB_${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Original free open-source forum written in Perl

LICENSE=	YABB_PUBLIC_LICENCE
LICENSE_NAME=	YABB PUBLIC LICENCE
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.yabbforum.com/licenses.php
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC

USES=		perl5 shebangfix zip
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes
WWWDOCROOT?=	www
YABBSUBDIR?=	yabb
YABBDIR?=	${WWWDOCROOT}/${YABBSUBDIR}
PLIST_SUB=	YABBDIR=${YABBDIR} \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}
DIR=		${PREFIX}/${YABBDIR}
WDIR=		${WRKSRC}/public_html/yabbfiles
WCGI=		${WRKSRC}/cgi-bin/yabb2
SUB_FILES=	pkg-message
SUB_LIST=	DIR=${DIR}
ISOFILES=	Admin/NewSettings.pm \
		Admin/Settings_Main.pm \
		Convert.pl Languages/English/Admin.lng \
		Setup.pl Sources/InstantMessage.pm \
		Sources/Post.pm Sources/Profile.pm \
		Sources/Subs.pm
PERLFILES=	AdminIndex.pl BoardConvert.pl Convert.pl \
		Convert2x.pl Setup.pl Sources/SpellChecker.pl YaBB.pl

post-extract:
	@${RM} -r ${WCGI}/Convert ${WCGI}/Modules ${WCGI}/FixFile.pl

post-patch:
.for _I in ${PERLFILES}
	@${SED} -i '' -e '1s|/usr/bin/perl|${perl_CMD}|' ${WCGI}/${_I}
.endfor
	@${CHMOD} -R a=,u+rwX ${WCGI}/*
	@${CHMOD} a=rx ${WCGI}/AdminIndex.pl ${WCGI}/Setup.pl ${WCGI}/YaBB.pl
	@${CHMOD} -R a-w ${WCGI}/Admin ${WCGI}/Languages ${WCGI}/Sources
	@${CHMOD} -R a=rX ${WDIR}/*
	@${CHMOD} -R u+w ${WDIR}/Attachments ${WDIR}/Templates

do-install:
	${INSTALL} -d ${STAGEDIR}${DIR}
	@cd ${WCGI} && ${COPYTREE_SHARE} . ${STAGEDIR}${DIR}/
	@cd ${WDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${DIR}/
	@${CHMOD} a=rx ${STAGEDIR}${DIR}

# Maintainer section
# The result goest to ISOFILES
#grep -l 8859 `find yabb -type f`

.include <bsd.port.mk>
