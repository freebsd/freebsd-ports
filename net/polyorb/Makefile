# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	polyorb
PORTVERSION=	2.9.0
CATEGORIES=	net
MASTER_SITES=	http://downloads.dragonlace.net/src/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	CORBA, SOAP, Ada 95 Distributed System Annex middleware

LICENSE=	GPLv3

BUILD_DEPENDS=	xmlada>=3.2:${PORTSDIR}/textproc/xmlada

USES+=		ada gmake
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PYTHON_BUILD=	yes

DESTINY=	${WRKDIR}/destino
MAKE_ENV=	DESTDIR=${DESTINY} \
		PROCESSORS=${MAKE_JOBS_NUMBER}
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD} \
		ac_cv_prog_CXXCPP="cpp -E" \
		ac_cv_prog_SVN=false

CONFIGURE_ARGS=	--with-appli-perso="corba dsa moma" \
		--with-proto-perso="giop soap srp" \
		--with-corba-services="event ir naming notification time"

# Polyorb 2011 = PCS version 4   GNAT GCC 4.6 = PCS version 4
# Polyorb 2012 = PCS version 5   GNAT GCC 4.7 = PCS version 5
# Polyorb 2013 = PCS version 6   GNAT GCC 4.8 = PCS version 6(?)
#
# Current gcc-aux expander is version 5, so Polyorb 2012 is the lastest
# version that it can build.  The versions have to match.
# However, GPL 2012 is particularly unstable, so a custom tarball from
# SVN revision 201373 has been created, which is the last of PCS version 5.

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} default

post-install:
	@cd ${DESTINY}${PREFIX}; ${FIND} * -type d -empty -print | ${XARGS} ${RMDIR}
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/
	@cd ${DESTINY}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${WRKDIR}/PLIST.all
	@cd ${DESTINY}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/lib\/gnat$$/d' -e '/share\/doc$$/d' -e '/share\/gps/d' \
	   -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@${CAT} ${WRKDIR}/PLIST.all >> ${TMPPLIST}

.include <bsd.port.mk>
