# Created by: Rihaz Jerrin <rihaz.jerrin@gmail.com>
# $FreeBSD$

PORTNAME=	cisco-torch
PORTVERSION=	0.4
DISTVERSIONSUFFIX=	b
CATEGORIES=	security
MASTER_SITES=	http://www.hackingciscoexposed.com/tools/

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	Mass Cisco Vulnerability Scanner

LICENSE=	LGPL21

RUN_DEPENDS=	p5-Net-Telnet>=0:net/p5-Net-Telnet \
		p5-Net-SSH2>=0:net/p5-Net-SSH2 \
		p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay

USES=		perl5 shebangfix
SHEBANG_FILES=	${WRKSRC}/cisco-torch.pl

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README.txt  TODO  CHANGELOG.txt  LICENSE
FILELIST=	brutefile.txt \
		community.txt \
		fingerprint.db \
		password.txt \
		tfingerprint.db \
		users.txt

do-install:
	${INSTALL_SCRIPT}   ${WRKSRC}/cisco-torch.pl ${STAGEDIR}${PREFIX}/bin/cisco-torch
	${MKDIR} 	    ${STAGEDIR}${DATADIR}/include
	${MKDIR} 	    ${STAGEDIR}${DATADIR}/tftproot
	${MKDIR}            ${STAGEDIR}${ETCDIR}
.for i in ${FILELIST}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor
	(cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${DATADIR})
	${MKDIR}  ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/torch.conf  ${STAGEDIR}${ETCDIR}/torch.conf.sample
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
