DISTFILES=	ispell-3.1.18.tar.gz
DISTNAME=	ispell-3.1
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/
CATEGORIES+=	utilities
MAKE_FLAGS=	TMPDIR=${.CURDIR} -f 
MAINTAINER=	jmz@FreeBSD.org

# French
#EXTRA_DICT=	   francais-IREQ-1.3.tar.gz
#MASTER_SITES+=    ftp://ftp.ireq-robot.hydro.qc.ca/pub/ispell/
CATEGORIES+=	utilities

DISTFILES+=	   ${EXTRA_DICT}

pre-configure:
.if defined(EXTRA_DICT)
	@echo ${EXTRA_DICT} > ${WRKDIR}/extra_dict
.else
	@echo -n
.endif

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/man/man4

.include <bsd.port.mk>
