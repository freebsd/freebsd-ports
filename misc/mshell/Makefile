DISTNAME=	mshell
DISTFILES=	7432.Z
MASTER_SITES=	ftp://src.doc.ic.ac.uk/usenet/alt.sources/articles/7000-7999/
NO_WRKSUBDIR=	yes

EXTRACT_COOKIE?=	${.CURDIR}/.extract_done

extract: fetch pre-extract ${EXTRACT_COOKIE}

${EXTRACT_COOKIE}:
	@echo "===>  Extracting for ${DISTNAME}"
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	zcat ${DISTDIR}/${DISTFILES} |(cd ${WRKDIR}; \
	awk '{if (/^#!/) x++} {if(x) print $$0'}| /bin/sh)
	@touch -f ${EXTRACT_COOKIE}

.include <bsd.port.mk>
