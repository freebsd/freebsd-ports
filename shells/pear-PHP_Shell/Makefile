# Ports collection makefile for:  pear-PHP_Shell
# Date created:			  05 August 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PHP_Shell
PORTVERSION=	0.3.1
CATEGORIES=	shells www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An interactive PHP Shell

USE_PHP=	pcre tokenizer readline

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		PHP/Shell.php \
		PHP/Shell/Commands.php PHP/Shell/Extensions.php \
		PHP/Shell/Options.php \
		PHP/Shell/Extensions/Autoload.php \
		PHP/Shell/Extensions/AutoloadDebug.php \
		PHP/Shell/Extensions/Colour.php \
		PHP/Shell/Extensions/ExecutionTime.php \
		PHP/Shell/Extensions/InlineHelp.php \
		PHP/Shell/Extensions/Prototypes.php \
		PHP/Shell/Extensions/VerbosePrint.php
EXAMPLES=	php-shell-cmd.php
SCRIPTSFILES=	php-shell-cmd.php php-shell.bat \
		php-shell.sh

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
