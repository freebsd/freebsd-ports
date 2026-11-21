# `zig2tuple` will spit out tuples like ".../source.tar.gz", those must be fixed
# to avoid collissions with other packages, but also version updates in the same
# package.
ZIG_TUPLE=	afl_kit:github.com/kristoff-it/zig-afl-kit/archive/e9b5dfc14c06133786a09214709316dc9fb54bd9.tar.gz:afl_kit-0.1.0-NdJ3ctQfAACNK1UANoF4pwkWOdW-JGLXHby9OE9-xMPq \
		ansi_term:github.com/kristoff-it/ansi_term/archive/c4679e859bd61259754bd312e59b54dd03957e90.tar.gz:ansi_term-0.3.0-_baAyzFoAACjFHF9VpZSo71Q7QUclZQlpYqZZShaNwYg \
		aro:codeberg.org/ziglang/arocc/archive/0871ead15c976711d98d302a601af3568703ee51.tar.gz:aro-0.0.0-JSD1QhOCNwCW5o94op15fl8SHmCMJbBf1cSWXUcpicml \
		cbor:github.com/neurocyte/cbor/archive/1e1a1c7e9e865b6c7df729bbff40a07f45774042.tar.gz:cbor-1.3.0-RcQE_EyKAQDhrVXsEQ9yqQMOV8uR7MWDLZZBHSwY8dAv \
		flow_syntax:github.com/neurocyte/flow-syntax/archive/641e1942c99734e25af8887b0e651ee068121189.tar.gz:flow_syntax-0.7.2-X8jOoa9VAgBX7T0oH-_x6AxtFMjFPmMXKGAMMwG9JZPk \
		frameworks:code.hexops.org/hexops/xcode-frameworks/archive/8a1cfb373587ea4c9bb1468b7c986462d8d4e10e.tar.gz:N-V-__8AALShqgXkvqYU6f__FrA22SMWmi2TXCJjNTO1m8XJ \
		gfm:github.com/kristoff-it/cmark-gfm/archive/58c054b81fdf126f0a2d4e079b25a39a4a5181c6.tar.gz:cmark_gfm-0.1.0-uQgTK1maFwCCg-Q8XWHN0d_rhFVUIem1qrMKMIZ5BJMR \
		known_folders:github.com/ziglibs/known-folders/archive/207c34a16e4365edc20d92c7892f962b3bed46e8.tar.gz:known_folders-0.0.0-Fy-PJsbKAACbDh9bBxR0MMThxZSS6A9RH4apWphNHY70 \
		lsp_kit:github.com/zigtools/lsp-kit/archive/3e1058db66079911fdde82f833fdce6856e0a706.tar.gz:lsp_kit-0.1.0-bi_PL9o2DADHS1PDra3MGz1MXnsboN_ewNvrc419z7Fb \
		mime:github.com/kristoff-it/mime/archive/a2ed0cba3b1463217168034ffed8c1604e72598d.tar.gz:mime-3.0.0-zwmL--0gAAByELrj57sRm2EFBRzjKLFrMgHQcs7sFZev \
		scripty:github.com/kristoff-it/scripty/archive/48006feaa0d75fd3548ae222d47c0ee9bf9f0a7a.tar.gz:scripty-0.1.0-LKK5O9kUAQB8WklvNpHxJ_mhlRotbxGaiR3GFmGdHm_V \
		superhtml:github.com/kristoff-it/superhtml/archive/b00f3d25e7e8103d18c08961ca39be7c282923ed.tar.gz:superhtml-0.7.1-Y7MdPL6bJgC9-jD4-EKen7iR9BOO6PGeWNQVlpWa-8Xx \
		supermd:github.com/kristoff-it/supermd/archive/d294f18f05b9f8ca908bbbe3778ae313ace629de.tar.gz:supermd-0.1.0-3Mco3FK_WADp-glLo0rNAfyuvGa2ksQZD9bY44TxrZ-Q \
		tracy:github.com/kristoff-it/tracy/archive/67d2d89e351048c76fc6d161e0ac09d8a831dc60.tar.gz:tracy-0.0.0-4Xw-1pwwAABTfMgoDP1unCbZDZhJEfict7XCBGF6IdIn \
		translate_c:codeberg.org/ziglang/translate-c/archive/5c31f38abf3aba28535ea545a2f393716c553d2c.tar.gz:translate_c-0.0.0-Q_BUWo5NBwB68fI9lsRU6WtgtSy9jS5M3hCFAjSrnY78 \
		tree_sitter:github.com/neurocyte/tree-sitter/releases/download/master-0324f7c57dd28ac6931fe8a4776b73859d8b4188/source.tar.gz?dummy=/0324f7c57dd28ac6931fe8a4776b73859d8b4188.tar.gz:tree_sitter-0.26.7-z0LhyFhXmDrEPNSZJ5asZtPpOOAj5xLRCVTVwjgBkQUV \
		wuffs:github.com/allyourcodebase/wuffs/archive/b410781f44698b221fb7c996323563f260eae944.tar.gz:wuffs-0.4.0-alpha.9+3837.20240914-3CHJgY8LAADtPnOWAFD0GgnP0MKcB9XPGy_WXENdJC6S \
		wuffs:github.com/google/wuffs-mirror-release-c/archive/90e4d81a6a8b7b601e8e568da32a105d7f7705e5.tar.gz:N-V-__8AANEmUgA6aZZZKbfNMv6DSs5In7CDFU6nInu_Y6aY \
		zeit:github.com/rockorager/zeit/archive/ed64c36035fe44d6372c20cbcd447b0090687167.tar.gz:zeit-0.10.0-dev-5I6bk4i0AgANIwpoMN_iBL-OGEpyDuInvQLfrPe_FVb1 \
		ziggy:github.com/kristoff-it/ziggy/archive/7fc62a537ba3e3a84287025b5b794e0cfaadef2f.tar.gz:ziggy-0.3.0-kTg8v_OsCAAdLrIXVYVI-z4bNEm5bBy_m13uu4Uy_2mb \
