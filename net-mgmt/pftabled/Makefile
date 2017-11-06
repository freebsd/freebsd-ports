# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	pftabled
PORTVERSION=	1.09
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to manage pf tables remotely

LICENSE=	BSD2CLAUSE

USES=		gmake shebangfix
SHEBANG_FILES=	pftabled-client.pl \
		pftabled-client.py
GNU_CONFIGURE=	yes

USE_RC_SUBR=	pftabled

PLIST_FILES=	bin/pftabled-client man/man1/pftabled.1.gz sbin/pftabled

OPTIONS_DEFINE=	PERLC PYTHONC
OPTIONS_DEFAULT=PERLC PYTHONC

PERLC_DESC=		Install sample Perl client
PERLC_PLIST_FILES=	bin/pftabled-client.pl
PERLC_USES=		perl5
PERLC_USE=		PERL5=run
PYTHONC_DESC=		Install sample Python client
PYTHONC_PLIST_FILES=	bin/pftabled-client.py
PYTHONC_USES=		python:run

post-install-PERLC-on:
	${INSTALL_SCRIPT} ${WRKSRC}/pftabled-client.pl ${STAGEDIR}${PREFIX}/bin/

post-install-PYTHONC-on:
	${INSTALL_SCRIPT} ${WRKSRC}/pftabled-client.py ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
