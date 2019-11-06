# $FreeBSD$

PORTNAME=	datawarrior
DISTVERSION=	5.0.0
CATEGORIES=	science java
MASTER_SITES=	https://www.dropbox.com/s/n3sjyh2ets71wo9/${DISTNAME}${EXTRACT_SUFX}?dl=1&dummy=/
DISTNAME=	datawarrior${DISTVERSION:S/.//g}Source

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemistry-aware multi-purpose data visualization and analysis program

BROKEN=		unfetchable

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl.txt

BUILD_DEPENDS=	openjfx8-devel>0:java/openjfx8-devel
RUN_DEPENDS=	openjfx8-devel>0:java/openjfx8-devel

USE_JAVA=	yes
USE_LOCALE=	en_US.UTF-8
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/publicSource

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./buildDataWarrior

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${FIND} ${STAGEDIR}${DATADIR} -name "*.java" -delete
	@cd ${STAGEDIR}${DATADIR} && ${RM} gpl.txt buildDataWarrior
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "cd ${DATADIR} && sh runDataWarrior"; \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# delete empty directories hierarchically
	@cd ${STAGEDIR}${DATADIR} && \
		while [ $$(${FIND} . -type d -empty | wc -l) != 0 ] ; do \
			${FIND} . -type d -empty -delete; \
		done

post-install: # autoplist: a lot of files in DATADIR
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${DATADIR:S/^${PREFIX}\///} -type f >> ${TMPPLIST}
	@${ECHO} "bin/${PORTNAME}" >> ${TMPPLIST}

.include <bsd.port.mk>
