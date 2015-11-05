# Created by: pauls
# $FreeBSD$

PORTNAME=	chaosreader
PORTVERSION=	0.94
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/
DISTFILES=	${PORTNAME}${PORTVERSION} sshkeydata0.20
EXTRACT_ONLY=
NO_WRKSUBDIR=	yes

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Tool to extract data from tcpdump logs

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run

PLIST_FILES=	bin/${PORTNAME} bin/sshkeydata
SHEBANG_FILES=	chaosreader sshkeydata

post-extract:
	@${CP} ${DISTDIR}/${PORTNAME}${PORTVERSION} ${WRKSRC}/${PORTNAME}
	@${CP} ${DISTDIR}/sshkeydata0.20 ${WRKSRC}/sshkeydata

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sshkeydata ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
