# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
# $FreeBSD$

PORTNAME=	dixit
PORTVERSION=	11.11
DISTVERSIONSUFFIX=	.${QT_VER}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION} \
		SF/${PORTNAME}/${PORTNAME}_qdb:db \
		LOCAL/bdrewery/${PORTNAME}/ \
		LOCAL/bdrewery/${PORTNAME}:db
DISTFILES=	${DISTNAME}.tgz \
		${_DB_D}:db
EXTRACT_ONLY=	${DISTNAME}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Romanian dictionaries databases and query application

LICENSE=	GPLv3+

USES=		qmake
USE_QT4=	corelib gui network moc_build rcc_build
LDFLAGS+=	-lz

PLIST_SUB=	_DB=${_DB} DB_DIR=${DB_DIR} _DB_F=${_DB_F} \
		DB_OWNER=${DB_OWNER} DB_GROUP=${DB_GROUP} DB_MODE=${DB_MODE}

QT_VER=		4

DB_DIR?=	/var/db/dixit
DB_OWNER?=	root
DB_GROUP?=	wheel
DB_MODE?=	0664
# DB_DATE is the time of the file in the zip archive, not the time of the last
# update of the database (which is a little earlier, but TZ makes it appear to
# be later), but it's all we can do in a makefile.
DB_DATE=201204010000
_DB_D=	${PORTNAME}.qdb.tar.bz2
_DB_F=	${PORTNAME}.qdb
_DB=	${DB_DIR}/${_DB_F}

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Your dictionary database directory is:"
	@${ECHO_MSG} "DB_DIR=${DB_DIR} (default /var/db/dixit)"
	@${ECHO_MSG} "You need about 65MB for the dictionary db."
	@${ECHO_MSG}
	@${ECHO_MSG} "You can allow all users to update (but potentially also delete"
	@${ECHO_MSG} "or alter) the dictionaries database by setting DB_MODE=0666"
	@${ECHO_MSG} "DB_OWNER=${DB_OWNER} (default: root)"
	@${ECHO_MSG} "DB_GROUP=${DB_GROUP} (default: wheel)"
	@${ECHO_MSG} "DB_MODE=${DB_MODE} (default: 0664)"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O3||' ${WRKSRC}/${PORTNAME}-${PORTVERSION}.${QT_VER}.pro
	@${REINPLACE_CMD} -e \
		's|dixit.qdb|${_DB}|' ${WRKSRC}/src/dixit.h

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DB_DIR}
	@${TOUCH} -t ${DB_DATE} ${WRKSRC}/${_DB_F}
	@${ECHO_MSG} "	===> Installing database ... .. ."
	@if [ ! -e "${_DB}" -o "${_DB}" -ot "${WRKSRC}/${_DB_F}" ]; \
		then	${TAR} -C ${STAGEDIR}${DB_DIR:S/${PORTNAME}//} -xf ${DISTDIR}/${_DB_D} && \
			${ECHO_MSG} "	===> ... Done."; \
		else	${ECHO_MSG} "	===> Exisitng database is newer, skiping";\
	fi

.include <bsd.port.mk>
