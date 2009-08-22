# Ports collection makefile for:  pear-Net_Vpopmaild
# Date created:			  12 April 2008
# Whom:				  Wen heping <wenheping@gmail.com>)
#
# $FreeBSD$
#

PORTNAME=	Net_Vpopmaild
PORTVERSION=	0.3.2
CATEGORIES=	net mail pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Class for accessing Vpopmail's vpopmaild daemon

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Vpopmaild.php \
		Vpopmaild/Base.php Vpopmaild/Exception.php \
		Vpopmaild/FatalException.php
DOCS=		docs.sh README
EXAMPLES=	login.php
TESTS=		000-vpopmaild-connect.phpt 005-vpopmaild-clogin.phpt \
		010-vpopmaild-setDebug.phpt \
		015-vpopmaild-status-functions.phpt \
		020-vpopmaild-acceptLog-recordio.phpt \
		025-vpopmaild-domainCount.phpt \
		030-vpopmaild-getGidBit.phpt \
		035-vpopmaild-setGidBit.phpt \
		040-vpopmaild-ip_map_tests.phpt \
		060-vpopmaild-dotQmailSplit.phpt \
		070-vpopmaild-robotSet.phpt \
		075-vpopmaild-robotGet.phpt \
		080-vpopmaild-robotDel.phpt \
		085-vpopmaild-listLists.phpt \
		090-vpopmaild-writeFile.phpt \
		095-vpopmaild-readFile.phpt \
		100-vpopmaild-rmFile.phpt 105-vpopmaild-mkDir.phpt \
		110-vpopmaild-listDir.phpt 115-vpopmaild-rmDir.phpt \
		125-vpopmaild-setLimits.phpt \
		130-vpopmaild-getLimits.phpt \
		135-vpopmaild-delLimits.phpt \
		140-vpopmaild-domainInfo.phpt \
		145-vpopmaild-listDomains.phpt \
		150-vpopmaild-addDomain.phpt \
		155-vpopmaild-addAliasDomain_delDomain.phpt \
		160-vpopmaild-findDomain.phpt \
		165-vpopmaild-authenticate.phpt \
		170-vpopmaild-add_del_mod-user-functions.phpt \
		185-vpopmaild-userInfo.phpt \
		190-vpopmaild-listUsers.phpt \
		195-vpopmaild-userCount.phpt \
		200-vpopmaild-getQuota.phpt \
		205-vpopmaild-getLastAuth.phpt \
		210-vpopmaild-isSysAdmin.phpt \
		215-vpopmaild-isDomainAdmin.phpt \
		220-vpopmaild-isUserAdmin.phpt \
		225-vpopmaild-readInfo.phpt \
		230-vpopmaild-formatBasePath.phpt \
		235-vpopmaild-setVacation.phpt \
		240-vpopmaild-getVacation.phpt \
		245-vpopmaild-delVacation.phpt \
		250-vpopmaild-aliasesToArray.phpt \
		255-vpopmaild-addAlias.phpt \
		260-vpopmaild-listAlias.phpt \
		265-vpopmaild-removeAlias.phpt \
		270-vpopmaild-deleteAlias.phpt \
		275-vpopmaild-getAliasContents.phpt \
		280-vpopmaild-parseAliases.phpt \
		285-vpopmaild-displayForwardLine.phpt \
		290-vpopmaild-paginateArray.phpt \
		README tests-config.php.dist \
		tests-setpath.php.dist

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
