#!/bin/sh

for f in ${TMPL_FILES}; do
	${SED} \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%EMACSDIR%%,${EMACSDIR},g" \
		-e "s,%%ELISPDIR%%,${ELISPDIR},g" \
		-e "s,%%INFODIR%%,${INFODIR},g" \
		-e "s,%%ETCDIR%%,${ETCDIR},g" \
		-e "s,%%PORTDIR%%,${PORTDIR},g" \
		-e "s,%%SAMPLEDIR%%,${SAMPLEDIR},g" \
		-e "s,%%REQUIRE%%,${REQUIRE},g" \
		-e "s,%%AWK%%,${AWK},g" \
		-e "s,%%CAT%%,${CAT},g" \
		-e "s,%%CP%%,${CP},g" \
		-e "s,%%ECHO%%,${ECHO},g" \
		-e "s,%%MKDIR%%,${MKDIR},g" \
		-e "s,%%RM%%,${RM},g" \
		-e "s,%%SED%%,${SED},g" \
		-e "s,%%TOUCH%%,${TOUCH},g" \
		-e "s,%%EMACS_CMD%%,${EMACS_CMD},g" \
		-e "s,%%PKGNAME%%,${PKGNAME},g" \
		-e "s,%%EMACS_PORT_NAME%%,${EMACS_PORT_NAME},g" \
		-e "s,%%VERSION%%,${VERSION},g" \
		< ${FILESDIR}/${f}.tmpl > ${WRKTMPDIR}/${f}
done
