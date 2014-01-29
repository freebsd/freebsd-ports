# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	bugmenot
PORTVERSION=	2.2
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Firefox extension to bypass compulsory web registration

LICENSE=	MPL GPLv2 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE=	license.txt

IGNORE=		bugmenot is incompatible with Firefox 26+

NO_STAGE=	yes

XPI_NUM=	6349
XPI_ID=		{987311C6-B504-4aa2-90BF-60CC49808D42}

USES=		dos2unix
DOS2UNIX_FILES=	license.txt

XPI_FILES=	chrome/bugmenot.jar install.rdf chrome.manifest license.txt	\
		defaults/preferences/prefs.js
XPI_DIRS=	chrome	defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
