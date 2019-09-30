# $FreeBSD$

PORTNAME=	pam_script
PORTVERSION=	1.1.9
CATEGORIES=	security
MASTER_SITES=	GH

MAINTAINER=	natalino.picone@nozominetworks.com
COMMENT=	PAM script module allows to hook user space scripts on PAM events

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	autoreconf libtool shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	etc/tally

GH_ACCOUNT=	jeroennijhof
GH_PROJECT=	pam_script
GH_TAGNAME=	1.1.9

GNU_CONFIGURE=	yes
PATCHDIR=	${.CURDIR}/files

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pam-script.d
	${INSTALL_LIB} ${WRKSRC}/.libs/pam_script.so ${STAGEDIR}${PREFIX}/lib/pam_script.so
	${INSTALL_SCRIPT} ${WRKSRC}/etc/pam_script ${STAGEDIR}${PREFIX}/etc/pam_script
.for i in etc/logscript etc/tally
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/etc/pam-script.d
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS COPYING ChangeLog README NEWS etc/README.pam_script etc/README.examples
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
