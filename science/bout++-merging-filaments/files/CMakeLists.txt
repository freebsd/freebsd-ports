cmake_minimum_required(VERSION 3.13)

project(merging-filaments LANGUAGES CXX)

find_package(bout++ REQUIRED) 

bout_add_example(merging-flux
  SOURCES merging-flux.cxx cephes/ellpe.cxx cephes/ellpk.cxx
)

install(
	TARGETS
		merging-flux
	DESTINATION
		bin
)
