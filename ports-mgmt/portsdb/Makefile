PORTNAME=	portsdb
DISTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program that imports the FreeBSD ports tree into an SQLite database
WWW=		https://github.com/yurivict/freebsd-portsdb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gsed:textproc/gsed \
		git:devel/git \
		sqlite3:databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	yurivict
GH_PROJECT=	freebsd-portsdb

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	# create folder
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec
	# copy files
	${CP} -r ${WRKSRC} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	# remove unnecessary files
.for file in .gitignore LICENSE README.md
	${RM} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/${file}
.endfor
	# create symlinks
.for prog in import update
	${RLN} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/${prog}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${prog}
.endfor

.include <bsd.port.mk>
