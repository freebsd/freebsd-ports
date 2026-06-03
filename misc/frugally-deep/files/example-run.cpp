// from README.md

#include <fdeep/fdeep.hpp>

int main() {
	try {
		const auto model = fdeep::load_model("fdeep_model.json");
		const auto result = model.predict(
			{fdeep::tensor(fdeep::tensor_shape(static_cast<std::size_t>(4)),
		std::vector<float>{1, 2, 3, 4})});
		std::cout << fdeep::show_tensors(result) << std::endl;
	} catch (std::runtime_error exception) {
		std::cerr << "Error: " << exception.what() << std::endl;
	}
}
