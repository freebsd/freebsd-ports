# Ports collection makefile for:  pear-Crypt_GPG
# Date created:			  14 Jan 2008
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt_GPG
PORTVERSION=	1.0.0
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	GNU Privacy Guard (GPG)

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	Crypt
FILES=		GPG/DecryptStatusHandler.php GPG/Key.php GPG/UserId.php \
		GPG/Engine.php GPG/Signature.php GPG/VerifyStatusHandler.php \
		GPG/Exceptions.php GPG/SubKey.php

TESTS=		AllTests.php GetFingerprintTestCase.php DecryptTestCase.php \
		GetKeysTestCase.php DeletePrivateKeyTestCase.php ImportKeyTestCase.php \
		DeletePublicKeyTestCase.php SignTestCase.php EncryptTestCase.php TestCase.php \
		ExportPublicKeyTestCase.php VerifyTestCase.php GeneralTestCase.php \
		data-files/testDecryptFile.asc data-files/testFileSmall.plain \
		data-files/testDecryptFileDual.asc data-files/testImportKeyFile_private.asc \
		data-files/testDecryptFileDualOnePassphrase.asc data-files/testImportKeyFile_public.asc \
		data-files/testDecryptFileKeyNotFoundException.asc data-files/testVerifyFileClearsignedData.asc \
		data-files/testDecryptFileNoPassphrase.asc data-files/testVerifyFileDualClearsignedData.asc \
		data-files/testDecryptFileToString.asc data-files/testVerifyFileDualNormalSignedData.asc \
		data-files/testFileEmpty.plain data-files/testVerifyFileNormalSignedData.asc \
		data-files/testFileMedium.plain

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
