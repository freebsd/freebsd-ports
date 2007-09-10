# 20050609 T.Bourke
# $FreeBSD$
# Install Isabelle from within FreeBSD ports.

DESTDIR=${PREFIX}/share/isabelle
SRCDIRS=bin contrib etc heaps lib src

all:
	./build -a -b

install:
	mkdir -p ${DESTDIR}
	${BSD_INSTALL_DATA} ANNOUNCE ${DESTDIR}/
	${BSD_INSTALL_DATA} CONTRIBUTORS ${DESTDIR}/
	${BSD_INSTALL_DATA} COPYRIGHT ${DESTDIR}/
	${BSD_INSTALL_DATA} NEWS ${DESTDIR}/
	${BSD_INSTALL_DATA} README ${DESTDIR}/
	${BSD_INSTALL_SCRIPT} build ${DESTDIR}/
	for f in ${SRCDIRS}; \
		do for g in `find -d $$f -type d`; \
		   do mkdir -p ${DESTDIR}/$$g; \
  files=`find -E $$g -depth 1 -type f -not -regex '.*\.(bak|orig)$$' -not -perm +u+x`; \
			    if [ "$$files" != "" ]; then ${BSD_INSTALL_DATA} \
			$$files ${DESTDIR}/$$g; fi; \
  scripts=`find -E $$g -depth 1 -type f -not -regex '.*\.(bak|orig)$$' -perm +u+x`; \
		     if [ "$$scripts" != "" ]; then ${BSD_INSTALL_SCRIPT} \
			$$scripts ${DESTDIR}/$$g; fi; \
		   done; \
		done

