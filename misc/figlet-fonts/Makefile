# New ports collection makefile for:	figlet-fonts
# Date created:			11 August 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	figlet-fonts
PORTVERSION=	20010811
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dd

MAINTAINER=	dd@FreeBSD.org

RUN_DEPENDS=	figlet:${PORTSDIR}/misc/figlet

NO_BUILD=	yes

.include <bsd.port.pre.mk>

FONTFILES!=	${CAT} ${FILESDIR}/fontfiles

do-install:
	@${INSTALL_DATA} ${FONTFILES:S/^/${WRKSRC}\//} ${PREFIX}/share/figlet

# Because of the large amount of files, I've decided not to have the
# port automatically download all of them, but instead have the
# maintainer generate the distfile.  The `tarball' target should take
# care of that.

REAL_MASTER_SITES=	\
	ftp://wuarchive.wustl.edu/graphics/graphics/misc/figlet/fonts/ \
	ftp://ftp.funet.fi/pub/unix/tools/figlet/fonts/

tarball:
	@${MKDIR} ${.CURDIR}/${DISTNAME}
.for __fx in ${FONTFILES}
	@${MKDIR} ${.CURDIR}/${DISTNAME}/${__fx:H}
	@for MASTER_SITE in ${REAL_MASTER_SITES}; do \
		if ${SETENV} ${FETCH_ENV} ${FETCH_CMD} \
			-o ${.CURDIR}/${DISTNAME}/${__fx} \
			${FETCH_BEFORE_ARGS} $${MASTER_SITE}${__fx} \
			${FETCH_AFTER_ARGS}; then \
				break; \
		fi; \
	done;
.endfor
	@cd ${.CURDIR} && ${TAR} -zcf ${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}

# Generate pkg-plist from files/fontfiles.

makelist:
	${CAT} ${FILESDIR}/fontfiles | ${SED} 's;^[^/]*/;share/figlet/;' \
		 > ${PLIST}

.include <bsd.port.post.mk>
